#pragma once
#include "mesh.hpp"

// holds pointers to everything for a Cloth object:
// - (2) GL buffer for predicted positions
// - (1) GL buffer for velocities
// - (4) GL buffers for internal forces


class Cloth : public Mesh
{
public:
  GLuint ssbo_pos_pred; // predicted positions buffer
  GLuint ssbo_vel; // shader storage buffer object -> holds velocities

  GLuint ssbo_internalConstraints[4];

  GLuint ssbo_collisionConstraints;

  // these vec3 constraints are index, index, rest length
  std::vector<glm::vec3> internalConstraints[4];
  std::vector<glm::vec3> externalConstraints; // pins

  Cloth(string filename);
  ~Cloth();
  void uploadAllConstraints(); // upload all determined constraints.

private:
  void generateConstraints();
};