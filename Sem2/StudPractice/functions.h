template <typename ArrayType>
ArrayType funcIsElement(ArrayType ar) {return ar;}
template <typename ArrayType>
ArrayType funcMultiply(ArrayType ar1, ArrayType ar2) {return ar1 * ar2;}
template <typename ArrayType>
ArrayType funcSum(ArrayType ar1, ArrayType ar2) {return ar1 + ar2;}
template <typename ArrayType>
ArrayType funcSearchMin(ArrayType ar1, ArrayType ar2) {return ar1<ar2? ar1 : ar2;}
template <typename ArrayType>
ArrayType funcSearchMax(ArrayType ar1, ArrayType ar2) {return ar1<ar2? ar2 : ar1;}