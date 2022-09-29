/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas
 * @author Jaime Armas Rivero
 * @since May 23 2022
 * @description Utils
 *       Differents utils to use in various files
 * @module utils
 */

/**
 * Get the values of a enum.
 * @param enumObject Enum to get the values
 * @return Array with the values of the enum
 */
export const getEnumValues = (enumObject: {
  [key: symbol | string]: number | string;
}): number[] => {
  const keys = Object.values(enumObject);
  const valuesSize = keys.length / 2;
  return keys.slice(-valuesSize) as number[];
};
