
namespace RectangleInfo {

	int verticeCount = 8;
	int faceCount = 4;

	float vertices[] = {
			-1.0f, 0.0f, -1.0f, 1.0f,
			-1.0f, 0.0f, 1.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 1.0f,
			1.0f, 0.0f, -1.0f, 1.0f,

			-1.0f, 0.0f, 1.0f, 1.0f,
			-1.0f, 0.0f, -1.0f, 1.0f,
			1.0f, 0.0f, -1.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 1.0f
	};

	float normals[] = {
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,

			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f
	};

	float texCoords[] = {
		0.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,

		0.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
	};

	unsigned int faceIndex[] = {
		0,1,2,0,2,3,
		4,5,6,4,6,7
	};

}
