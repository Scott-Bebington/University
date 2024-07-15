#version 330 core
    in vec2 UV;
    out vec4 FragColor;
    uniform sampler2D diffuseTexture;
    uniform vec4 diffuseColor; // Now includes alpha
    void main() {
      bool isTexturedFace = (gl_FrontFacing == true);
      vec4 texColor = vec4(1.0); // Default white color
      if (isTexturedFace) {
        texColor = texture(diffuseTexture, UV);
      } else {
        texColor = diffuseColor;
      }
      FragColor = texColor;
    }