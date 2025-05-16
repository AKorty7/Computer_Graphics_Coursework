#include "scene.hpp"

Scene::Scene() {
    initGround();
    initBenches();
    initTrees();
}

Scene::~Scene() {
    glDeleteVertexArrays(1, &groundVAO);
    glDeleteBuffers(1, &groundVBO);
    glDeleteVertexArrays(1, &benchVAO);
    glDeleteBuffers(1, &benchVBO);
    glDeleteVertexArrays(1, &treeVAO);
    glDeleteBuffers(1, &treeVBO);
}

void Scene::initGround() {
    float vertices[] = {
        // Positions        // Normals         // TexCoords
        -5.0f, 0.0f, -5.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
         5.0f, 0.0f, -5.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
         5.0f, 0.0f,  5.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        -5.0f, 0.0f,  5.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f
    };
    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    glGenVertexArrays(1, &groundVAO);
    glGenBuffers(1, &groundVBO);
    glBindVertexArray(groundVAO);
    glBindBuffer(GL_ARRAY_BUFFER, groundVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glGenBuffers(1));
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glBindVertexArray(0);
}

void Scene::initBenches() {
    float vertices[] = {
        // Positions        // Normals         // TexCoords
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
        // ... (remaining cube vertices for 6 faces)
        -0.5f, -0.5f,  0.5f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,
         0.5f, -0.5f,  0.5f, 0.0f, 0.0f,  1.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 0.0f, 0.0f,  1.0f, 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f, 0.0f, 0.0f,  1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
         0.5f, -0.5f,  0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, 0.0f,
         0.5f,  0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f
    };
    unsigned int indices[] = {
        0, 1, 2, 2, 3, 0,
        4, 5, 6, 6, 7, 4,
        8, 9, 10, 10, 11, 8,
        12, 13, 14, 14, 15, 12,
        16, 17, 18, 18, 19, 16,
        20, 21, 22, 22, 23, 20
    };

    glGenVertexArrays(1, &benchVAO);
    glGenBuffers(1, &benchVBO);
    glBindVertexArray(benchVAO);
    glBindBuffer(GL_ARRAY_BUFFER, benchVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glGenBuffers(1));
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glBindVertexArray(0);

    benchModels.push_back(glm::translate(glm::mat4(1.0f), glm::vec3(-2.0f, 0.5f, -2.0f)));
    benchModels.push_back(glm::translate(glm::mat4(1.0f), glm::vec3(2.0f, 0.5f, 2.0f)));
}

void Scene::initTrees() {
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    const int slices = 20;
    const int stacks = 20;
    const float radius = 0.5f;

    for (int i = 0; i <= stacks; ++i) {
        float phi = i * glm::pi<float>() / stacks;
        float sinPhi = sin(phi);
        float cosPhi = cos(phi);
        for (int j = 0; j <= slices; ++j) {
            float theta = j * 2 * glm::pi<float>() / slices;
            float sinTheta = sin(theta);
            float cosTheta = cos(theta);

            float x = cosTheta * sinPhi;
            float y = cosPhi;
            float z = sinTheta * sinPhi;

            vertices.push_back(radius * x);
            vertices.push_back(radius * y + 1.0f);
            vertices.push_back(radius * z);

            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);

            vertices.push_back(static_cast<float>(j) / slices);
            vertices.push_back(static_cast<float>(i) / stacks);
        }
    }

    for (int i = 0; i < stacks; ++i) {
        for (int j = 0; j < slices; ++j) {
            int k1 = i * (slices + 1) + j;
            int k2 = k1 + slices + 1;
            indices.push_back(k1);
            indices.push_back(k2);
            indices.push_back(k1 + 1);
            indices.push_back(k2);
            indices.push_back(k2 + 1);
            indices.push_back(k1 + 1);
        }
    }

    glGenVertexArrays(1, &treeVAO);
    glGenBuffers(1, &treeVBO);
    glBindVertexArray(treeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, treeVBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glGenBuffers(1));
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
    glBindVertexArray(0);

    treeModels.push_back(glm::translate(glm::mat4(1.0f), glm::vec3(3.0f, 0.0f, -3.0f)));
    treeModels.push_back(glm::translate(glm::mat4(1.0f), glm::vec3(-3.0f, 0.0f, 3.0f)));
}

void Scene::render(Shader& shader) {
    // Render ground
    glBindVertexArray(groundVAO);
    glm::mat4 model = glm::mat4(1.0f);
    shader.setMat4("model", model);
    shader.setBool("isGround", true);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    // Render benches
    shader.setBool("isGround", false);
    glBindVertexArray(benchVAO);
    for (const auto& benchModel : benchModels) {
        shader.setMat4("model", benchModel);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    }

    // Render trees
    glBindVertexArray(treeVAO);
    for (const auto& treeModel : treeModels) {
        shader.setMat4("model", treeModel);
        glDrawElements(GL_TRIANGLES, 6 * 20 * 20, GL_UNSIGNED_INT, 0);
    }
    glBindVertexArray(0);
}