#include <vector>

#ifndef MODEL_H
#define MODEL_H

class Model {
    public:
        Model (const std::vector<float>& vertices, const std::vector<unsigned int>& indices, const std::vector<unsigned int>& attribLengths);
        void Bind ();

        float* vertices;
        unsigned int* indices;

        unsigned int* attribLen;

        int totalVertices;
        int attrPerVert;
        int totalIndices;

        unsigned int VAO, EBO, VBO;

        std::vector<unsigned int> textures;


        static Model joinModels (Model models[]);
};

#endif