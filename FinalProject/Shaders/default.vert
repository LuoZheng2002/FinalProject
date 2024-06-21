#version 330 core
layout (location=0) in vec3 aPos;
layout (location=1) in vec3 aColor;
layout (location=2) in vec2 aTex;
layout (location=3) in vec3 aNormal;
layout (location=4) in vec3 bone;
out vec3 color;
out vec2 texCoord;
out vec3 Normal;
out vec3 crntPos;
uniform float scale;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

uniform mat4 translation1;
uniform mat4 translation2;
uniform mat4 rotation1;
uniform mat4 rotation2;

void main()
{
    mat4 bend1 = translation1 * rotation1 * inverse(translation1);
    mat4 bend2 = translation1 * rotation1 * translation2 * rotation2 * inverse(translation2) * inverse(translation1);
    
    vec3 crntPos1 = aPos;
    vec3 crntPos2 = vec3(bend1 * vec4(aPos, 1.0f));
    vec3 crntPos3 = vec3(bend2 * vec4(aPos, 1.0f));
    crntPos = vec3(model * vec4(crntPos1 * bone.x + crntPos2*bone.y + crntPos3*bone.z, 1.0f));
    gl_Position = proj * view * vec4(crntPos, 1.0f);
    color = aColor;
    texCoord = aTex;
    vec4 normal4D = model * vec4(aNormal, 1.0f);
    Normal = vec3(normal4D.x, normal4D.y, normal4D.z);
}