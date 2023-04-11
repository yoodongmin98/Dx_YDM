//////////////////////////////////////////
//
// NOTE: This is *not* a valid shader file
//
///////////////////////////////////////////
Shader "Unlit/Water2DCaustics" {
Properties {
_MainTex ("Main Texture", 2D) = "white" { }
_Color ("Color", Color) = (1,1,1,0.5)
_Refraction ("Refraction", 2D) = "bump" { }
_Intensity ("Refraction Intensity", Float) = 0.02
_Current ("Current Speed", Float) = -0.25
_Illum ("Illum", 2D) = "white" { }
_IllumFadeFactor ("Illum Fade Factor", Range(0.01, 3)) = 1
}
SubShader {
 Tags { "IGNOREPROJECTOR" = "true" "PreviewType" = "Plane" "QUEUE" = "Transparent" "RenderType" = "Transparent" }
 GrabPass {
}
 Pass {
  Tags { "IGNOREPROJECTOR" = "true" "PreviewType" = "Plane" "QUEUE" = "Transparent" "RenderType" = "Transparent" }
  Blend One OneMinusSrcAlpha, One OneMinusSrcAlpha
  ZWrite Off
  Cull Off
  GpuProgramID 17823
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