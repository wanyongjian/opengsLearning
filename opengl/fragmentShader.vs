#version 330 core
out vec4 FragColor;

in vec3 ourColor;
//in vec2 TexCoord;
//uniform vec4 gColor;
//uniform sampler2D texture1;
//uniform sampler2D texture2;
void main()
{
//    FragColor = vec4(ourColor, 1.0f);
//    FragColor = gColor;
//    FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
    FragColor = vec4(1.0);
}

