using System;
using System.Collections.Generic;
using System.Drawing;

namespace IndividualTask
{
    partial class Form1
    {
        private void SetReactions(List<IParticle> reagents)
        {
            var newContents = new List<IParticle>();
            int i = 0;
            while (i < reagents.Count)
            {
                var thisReagent = reagents[i];
                var thisReagentLocation = TDim.TTT.Projection(thisReagent.GetCoords());
                var closestReagents = new List<IParticle>();
                _tree.GetContentsLimited(closestReagents,
                    new Rectangle(thisReagentLocation.X - 20, thisReagentLocation.Y - 20, 40, 40));
                i++;
                foreach (var anotherReagent in closestReagents)
                {
                    if (!thisReagent.Equals(anotherReagent) && _tempCoeff>0)
                    {
                        
                        var thisType = thisReagent.GetType().ToString().Split('.')[1];
                        var anotherType = anotherReagent.GetType().ToString().Split('.')[1];
                        var center = (thisReagent.GetCoords() + anotherReagent.GetCoords()) / 2;
                        bool reactionCompleted = true;
                        
                        if (thisType[0] == anotherType[0])
                        {
                            #region AtomReactions
                            if (thisType[0] == 'A')
                            {
                                if (thisType == anotherType && thisType[1] != 'P')
                                {
                                    switch (thisType[1])
                                    {
                                        case 'H':
                                            newContents.Add(new MHydrogen(center.x, center.y, center.z));
                                            break;
                                        case 'O':
                                            newContents.Add(new MOxygen(center.x, center.y, center.z));
                                            break;
                                        case 'C':
                                            newContents.Add(new MChlorine(center.x, center.y, center.z));
                                            break;
                                    }
                                }
                                else reactionCompleted = false;
                            }
                            #endregion
                            #region MoleculeReactions
                            else
                            {
                                switch (thisType + anotherType)
                                {
                                    case "MHydrogenMOxygen":
                                    case "MOxygenMHydrogen":
                                        newContents.Add(new MHOH(center.x+10,center.y,center.z));
                                        newContents.Add(new AOxygen(center.x,center.y+10,center.z));
                                        break;
                                    case "MHydrogenMChlorine":
                                    case "MChlorineMHydrogen":
                                        newContents.Add(new MHCl(center.x+10,center.y,center.z));
                                        newContents.Add(new MHCl(center.x,center.y+10,center.z));
                                        break;
                                    case "MHOHMKCl":
                                    case "MKClMHOH":
                                        newContents.Add(new AHydrogen(center.x,center.y+10,center.z));
                                        newContents.Add(new AChlorine(center.x+10,center.y,center.z));
                                        newContents.Add(new MKOH(center.x,center.y,center.z));
                                        break;
                                    default:
                                        reactionCompleted = false;
                                        break;
                                }
                            }
                            #endregion
                        }
                        else
                        {
                            if (thisType + anotherType == "MHClAPotassium" || thisType + anotherType == "APotassiumMHCl")
                            {
                                newContents.Add(new MKCl(center.x+10, center.y, center.z));
                                newContents.Add(new AHydrogen(center.x, center.y+10, center.z));
                            }
                            else reactionCompleted = false;
                        }
                        if (reactionCompleted)
                        {
                            i--;
                            reagents.Remove(thisReagent);
                            reagents.Remove(anotherReagent);
                            thisReagent.Clear(_graphics,_drawState);
                            anotherReagent.Clear(_graphics,_drawState);
                            break;
                        }
                    }
                }
            }

            foreach (var item in newContents)
            {
                reagents.Add(item);
            }
        }

        private void ApplyForce(List<IParticle> particles)
        {
            foreach (var particle in particles)
            {
                foreach (var nearbyParticle in particles)
                {
                    if (!nearbyParticle.Equals(particle) && _tempCoeff>0)
                    {
                        var dS = (particle.GetCoords()-nearbyParticle.GetCoords())*Math.Pow(3/TDim.TTT.Radius(particle.GetCoords(), nearbyParticle.GetCoords()),2);
                        if (TDim.TTT.Radius(particle.GetCoords(), nearbyParticle.GetCoords())>=10)
                        {
                            particle.SetCoords(particle.GetCoords() - dS);
                            nearbyParticle.SetCoords(nearbyParticle.GetCoords() + dS);
                        }
                        else
                        {
                            particle.SetCoords(particle.GetCoords() + dS*2);
                            nearbyParticle.SetCoords(nearbyParticle.GetCoords() - dS*2);
                        }
                    }
                }
            }
        }
    }
}