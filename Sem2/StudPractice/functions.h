/*
 * Файлик с основнымми функциями
 * Стандартно используется пара "funcIsElement и funcSearchMin", что дает минимум функции
 * Для большинства функций поиска годится funcIsElement,
 * Однако, если хотим найти количество элементов опрделенного значения, то
 * используется пара funcIsEquals и funcSum
 */

//Предопределение значения для сравнения
template <typename ArrayType>
ArrayType eqValue = 1;
template <typename ArrayType>
ArrayType chValue = 1;

//Не производит каких-либо операций над значением
template <typename ArrayType>
ArrayType funcIsElement(ArrayType ar) {return ar;}
//Сравнение с предопределенным значением
template <typename ArrayType>
ArrayType funcIsEquals(ArrayType ar) {return ar == eqValue<ArrayType>;}
template <typename ArrayType>
ArrayType funcIncElement(ArrayType ar) {return ar + chValue<ArrayType>;}
template <typename ArrayType>
ArrayType funcDecElement(ArrayType ar) {return ar - chValue<ArrayType>;}
template <typename ArrayType>
ArrayType funcMultiElement(ArrayType ar) {return ar * chValue<ArrayType>;}
template <typename ArrayType>
ArrayType funcDivElement(ArrayType ar) {return ar / chValue<ArrayType>;}
template <typename ArrayType>
ArrayType funcMultiply(ArrayType ar1, ArrayType ar2) {return ar1 * ar2;}
template <typename ArrayType>
ArrayType funcSum(ArrayType ar1, ArrayType ar2) {return ar1 + ar2;}
template <typename ArrayType>
ArrayType funcSearchMin(ArrayType ar1, ArrayType ar2) {return ar1<ar2? ar1 : ar2;}
template <typename ArrayType>
ArrayType funcSearchMax(ArrayType ar1, ArrayType ar2) {return ar1<ar2? ar2 : ar1;}