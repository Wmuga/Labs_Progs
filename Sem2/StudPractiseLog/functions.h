/*
 * Файлик с основнымми функциями
 * Стандартно используется пара "funcIsElement и funcSearchMin", что дает минимум функции
 * Для большинства функций поиска годится funcIsElement,
 * Однако, если хотим найти количество элементов опрделенного значения, то
 * используется пара funcIsEquals и funcSum
 */

//Предопределение значения для сравнения
template <typename ArrayType>
ArrayType eqValue;
template <typename ArrayType>
ArrayType chValue;

//Не производит каких-либо операций над значением
template <typename ArrayType>
ArrayType funcIsElement(ArrayType ar) {return ar;}
//Сравнение с предопределенным значением
template <typename ArrayType>
ArrayType funcIsEquals(ArrayType ar) {return ar == eqValue<ArrayType>;}
template <typename ArrayType>
ArrayType funcIncElement(ArrayType ar) {ar+=chValue<ArrayType>;
    return ar;}
template <typename ArrayType>
ArrayType funcDecElement(ArrayType ar) {ar-=chValue<ArrayType>;
    return ar;}
template <typename ArrayType>
ArrayType funcMultiElement(ArrayType ar) {ar*=chValue<ArrayType>;
    return ar;}
template <typename ArrayType>
ArrayType funcDivElement(ArrayType ar) { ar/=chValue<ArrayType>;
    return ar;}
template <typename ArrayType>
ArrayType funcMultiply(ArrayType ar1, ArrayType ar2) {return ar1 * ar2;}
template <typename ArrayType>
ArrayType funcSum(ArrayType ar1, ArrayType ar2) {return ar1 + ar2;}
template <typename ArrayType>
ArrayType funcSearchMin(ArrayType ar1, ArrayType ar2) {return ar1<ar2? ar1 : ar2;}
template <typename ArrayType>
ArrayType funcSearchMinMore(ArrayType ar1, ArrayType ar2) {
    if (ar1<=eqValue<ArrayType> and ar2<=eqValue<ArrayType>) return funcMultiply(ar1,ar2);
    if (ar1<=eqValue<ArrayType>) return ar2;
    if (ar2<=eqValue<ArrayType>) return ar1;
    return funcSearchMin(ar1,ar2);
}
template <typename ArrayType>
ArrayType funcSearchMax(ArrayType ar1, ArrayType ar2) {return ar1<ar2? ar2 : ar1;}