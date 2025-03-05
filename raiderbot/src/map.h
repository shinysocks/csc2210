/*
 * map.h
 *
 *      Author: [[TODO]]
 */

#ifndef MAP_H_
#define MAP_H_

// the following line (declaration) ensures do not to include cell.h
class MapCell;

// Track the area the robot in which the robot moves.
// Note you will need to add declarations for the height and width.
// Add other methods and data as needed.
class Map {
  MapCell *cells[WIDTH][HEIGHT];
public:
  // initialize empty map
  Map();
  // read the map from cin
  void load();
  // write the full map to cout
  void write();
};

#endif /* MAP_H_ */
