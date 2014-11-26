varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

uniform vec2 position;
uniform float lightSize;

void main()
{
    float darkness = 0.7;
    gl_FragColor = vec4(vec3(gl_FragColor.xyz), darkness);
    vec2 centerPos = gl_FragCoord.xy - vec2(position.x, position.y);
    //calculate light density
    float z = sqrt(lightSize*lightSize - centerPos.x*centerPos.x - centerPos.y*centerPos.y);
    z /= lightSize;
    if (length(centerPos) < lightSize) {
        gl_FragColor.a = darkness - z;
    }
}