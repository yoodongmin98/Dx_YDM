//////////////////////////////////////////
//
// NOTE: This is *not* a valid shader file
//
///////////////////////////////////////////
Shader "Hidden/NormalFromHeightMap" {
Properties {
_MainTex ("Texture", 2D) = "grey" { }
}
SubShader {
 Pass {
  GpuProgramID 38461
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