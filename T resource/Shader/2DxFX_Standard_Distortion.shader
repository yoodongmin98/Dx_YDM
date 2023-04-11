//////////////////////////////////////////
//
// NOTE: This is *not* a valid shader file
//
///////////////////////////////////////////
Shader "2DxFX/Standard/Distortion" {
Properties {
_MainTex ("Base (RGB)", 2D) = "white" { }
_OffsetX ("OffsetX", Range(0, 128)) = 0
_OffsetY ("OffsetY", Range(0, 128)) = 0
_DistanceX ("DistanceX", Range(0, 1)) = 0
_DistanceY ("DistanceY", Range(0, 1)) = 0
_WaveTimeX ("WaveTimeX", Range(0, 360)) = 0
_WaveTimeY ("WaveTimeY", Range(0, 360)) = 0
_Color ("Tint", Color) = (1,1,1,1)
_Alpha ("Alpha", Range(0, 1)) = 1
_StencilComp ("Stencil Comparison", Float) = 8
_Stencil ("Stencil ID", Float) = 0
_StencilOp ("Stencil Operation", Float) = 0
_StencilWriteMask ("Stencil Write Mask", Float) = 255
_StencilReadMask ("Stencil Read Mask", Float) = 255
_ColorMask ("Color Mask", Float) = 15
}
SubShader {
 Tags { "IGNOREPROJECTOR" = "true" "QUEUE" = "Transparent" "RenderType" = "Transparent" }
 Pass {
  Tags { "IGNOREPROJECTOR" = "true" "QUEUE" = "Transparent" "RenderType" = "Transparent" }
  Blend SrcAlpha OneMinusSrcAlpha, SrcAlpha OneMinusSrcAlpha
  ZWrite Off
  Cull Off
  Stencil {
   ReadMask 0
   WriteMask 0
   Comp Disabled
   Pass Keep
   Fail Keep
   ZFail Keep
  }
  GpuProgramID 56710
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
Fallback "Sprites/Default"
}