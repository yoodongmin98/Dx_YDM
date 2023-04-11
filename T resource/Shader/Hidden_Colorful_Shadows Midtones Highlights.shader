//////////////////////////////////////////
//
// NOTE: This is *not* a valid shader file
//
///////////////////////////////////////////
Shader "Hidden/Colorful/Shadows Midtones Highlights" {
Properties {
_MainTex ("Base (RGB)", 2D) = "white" { }
_Shadows ("Shadows (RGB)", Vector) = (1,1,1,1)
_Midtones ("Midtones (RGB)", Vector) = (1,1,1,1)
_Highlights ("Highlights (RGB)", Vector) = (1,1,1,1)
_Amount ("Amount (Float)", Range(0, 1)) = 1
}
SubShader {
 Pass {
  ZTest Always
  ZWrite Off
  Cull Off
  Fog {
   Mode Off
  }
  GpuProgramID 46208
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
 Pass {
  ZTest Always
  ZWrite Off
  Cull Off
  Fog {
   Mode Off
  }
  GpuProgramID 95399
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