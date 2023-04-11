//////////////////////////////////////////
//
// NOTE: This is *not* a valid shader file
//
///////////////////////////////////////////
Shader "Hidden/AmbientWaves" {
Properties {
_MainTex ("Texture", 2D) = "grey" { }
_FadeDistance ("Amplitude Fall off", Range(0, 1)) = 0.5
}
SubShader {
 Pass {
  GpuProgramID 10467
Program "vp" {
SubProgram "d3d11 " {
"// shader disassembly not supported on DXBC"
}
}
Program "fp" {
SubProgram "d3d11 " {
"// shader disassembly not supported on DXBC"
}
}
}
}
}