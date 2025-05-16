#ifndef SCENE_HPP
#define SCENE_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class Scene {
private:
    GLuint groundVAO, groundVBO, groundEBO;
    GLuint benchVAO, benchVBO, benchEBO;
    GLuint treeVAO, treeVBO, treeEBO;
    std::vector<glm::mat4> benchModels;
    std::vector<glm::mat4> treeModels;

    void initGround();
    void initBenches();
    void initTrees();

public:
    Scene();
    ~Scene();
    void render(GLuint shaderProgram);
};

#endif //