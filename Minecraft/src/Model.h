#ifndef MODEL_H
#define MODEL_H

class Model {
    public:
        Model(float vertices[], int indices[], float attribLengths[]);

        float* vertices;
        int* indices;
        int totalIndices;
        int totalVertices;

        unsigned int VAO, EBO, VBO;


        static Model joinModels(Model models[]);
};

#endif