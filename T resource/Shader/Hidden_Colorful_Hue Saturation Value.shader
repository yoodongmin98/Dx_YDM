//////////////////////////////////////////
//
// NOTE: This is *not* a valid shader file
//
///////////////////////////////////////////
Shader "Hidden/Colorful/Hue Saturation Value" {
Properties {
_MainTex ("Base (RGB)", 2D) = "white" { }
_Master ("Master (HSV)", Vector) = (0,0,0,0)
_Reds ("Reds (HSV)", Vector) = (0,0,0,0)
_Yellows ("Yellows (HSV)", Vector) = (0,0,0,0)
_Greens ("Greens (HSV)", Vector) = (0,0,0,0)
_Cyans ("Cyans (HSV)", Vector) = (0,0,0,0)
_Blues ("Blues (HSV)", Vector) = (0,0,0,0)
_Magentas ("Magentas (HSV)", Vector) = (0,0,0,0)
}
SubShader {
 Pass {
  ZTest Always
  ZWrite Off
  Cull Off
  Fog {
   Mode Off
  }
  GpuProgramID 372
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
  GpuProgramID 120284
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