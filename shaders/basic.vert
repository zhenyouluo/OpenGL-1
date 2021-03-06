#version 330

in vec3 position;
uniform mat4 mvpMatrix;

void main(void)
{
	gl_Position = mvpMatrix * vec4(position, 1.0);
}
