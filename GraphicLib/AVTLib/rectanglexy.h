
namespace RectangleXYInfo {

    int verticeCount = 4;
    int faceCount = 2;

    float vertices[] = {
            0.0f, 0.0f, 0.0f, 1.0f,
            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 0.0f, 1.0f
    };

    float normals[] = {
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f
    };

    float texCoords[] = {
            0.0f, 1.0f,
            0.0f, 0.0f,
            1.0f, 0.0f,
            1.0f, 1.0f
    };

    unsigned int faceIndex[] = {
            0, 1, 2, 0, 2, 3
    };

}
