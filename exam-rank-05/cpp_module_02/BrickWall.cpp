#include "BrickWall.hpp"

BrickWall::BrickWall() { type = "Inconspicuous Red-brick Wall"; }

BrickWall::~BrickWall() {}

ATarget* BrickWall::clone() const { return new BrickWall(); }
