
attribute vec4 a_position;
uniform vec4 u_color;
uniform float u_pointSize;

varying vec4 v_fragmentColor;

void main()
{
    gl_Position = CC_PMatrix * a_position;
}
