//////////////////////////////////////////
//
// NOTE: This is *not* a valid shader file
//
///////////////////////////////////////////
Shader "Water2D/LitWaterRippleAdvanced_TM" {
Properties {
_MainTex ("Base (RGB)", 2D) = "grey" { }
_ReflectionTex ("", 2D) = "white" { }
_DeepWaterColor ("Deep Water Color", Color) = (1,1,1,1)
_ShallowWaterColor ("Shalow Water Color", Color) = (0.73,0.92,0.99,1)
_UnderWaterOpacity ("Under Water Opacity", Range(0, 1)) = 0.4
[KeywordEnum(PerPixel, PerVertex)] _Normals ("Normals", Float) = 0
_NormalStrength ("Normal Strength", Float) = 15
_CubeMapLevel ("Sky Box Reflection", Range(0, 1)) = 0.2
_EdgeBlend ("Edge Blend", Float) = 4
_WaterDepth ("Water Depth", Float) = 0.6
_Smoothness ("Reflection Intensity", Range(0, 1)) = 0.8
_FresnelPower ("Fresnel Power", Float) = 0.2
_FresnelBias ("Fresnel Bias", Float) = 0.2
[Toggle(_SPECULAR_ON)] _SPECULAR ("Specular Reflection", Float) = 0
_SpecularColor ("Specular Color", Color) = (0.72,0.72,0.72,1)
_WorldLightDir ("Specular Light Direction", Vector) = (0,0.1,-0.5,0)
_Shininess ("Shininess", Range(2, 500)) = 200
_Distortion ("Distortion", Range(0, 1.5)) = 0.168
_BumpTiling ("Bump Tiling", Vector) = (0.04,0.04,0.04,0.08)
_BumpDirection ("Bump Speed (Map1 x, y, Map2 z, w)", Vector) = (1,30,20,-20)
_BumpMap ("Bump Normals", 2D) = "bump" { }
_Cube ("Cube Map", Cube) = "black" { }
[Toggle(_FOAM_ON)] _FOAM ("Enable Foam", Float) = 0
_FoamColor ("FoamColor", Color) = (1,1,1,1)
_FoamTex ("Foam Texture", 2D) = "white" { }
_FoamGradient ("Foam Gradient ", 2D) = "white" { }
_FoamStrength ("Foam Strength", Float) = 0.4
_WaveHeightScale ("Wave Height Scale", Float) = 1
_FaceCulling ("", Float) = 2
_OneOrZero ("One Or Zero", Float) = 0
_HeightOffset (" ", Float) = 0
_BottomPos (" ", Float) = -2
}
SubShader {
 Tags { "IGNOREPROJECTOR" = "true" "QUEUE" = "Transparent" "RenderType" = "Transparent" }
 GrabPass {
  "_RefractionTexLit_TM"
}
 Pass {
  Name "FORWARD"
  Tags { "IGNOREPROJECTOR" = "true" "LIGHTMODE" = "FORWARDBASE" "QUEUE" = "Transparent" "RenderType" = "Transparent" }
  Blend SrcAlpha OneMinusSrcAlpha, SrcAlpha OneMinusSrcAlpha
  Cull Off
  GpuProgramID 64004
Program "vp" {
SubProgram "d3d11 " {
Keywords { "DIRECTIONAL" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "DIRECTIONAL" "LIGHTPROBE_SH" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "DIRECTIONAL" "VERTEXLIGHT_ON" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "DIRECTIONAL" "LIGHTPROBE_SH" "VERTEXLIGHT_ON" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
}
Program "fp" {
SubProgram "d3d11 " {
Keywords { "DIRECTIONAL" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "DIRECTIONAL" "LIGHTPROBE_SH" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
}
}
 Pass {
  Name "FORWARD"
  Tags { "IGNOREPROJECTOR" = "true" "LIGHTMODE" = "FORWARDADD" "QUEUE" = "Transparent" "RenderType" = "Transparent" }
  Blend One One, One One
  ZWrite Off
  Cull Off
  GpuProgramID 84177
Program "vp" {
SubProgram "d3d11 " {
Keywords { "POINT" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "DIRECTIONAL" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "SPOT" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "POINT_COOKIE" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "DIRECTIONAL_COOKIE" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
}
Program "fp" {
SubProgram "d3d11 " {
Keywords { "POINT" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "DIRECTIONAL" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "SPOT" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "POINT_COOKIE" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "DIRECTIONAL_COOKIE" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
}
}
 Pass {
  Name "PREPASS"
  Tags { "IGNOREPROJECTOR" = "true" "LIGHTMODE" = "PREPASSBASE" "QUEUE" = "Transparent" "RenderType" = "Transparent" }
  Blend SrcAlpha OneMinusSrcAlpha, SrcAlpha OneMinusSrcAlpha
  Cull Off
  GpuProgramID 137031
Program "vp" {
SubProgram "d3d11 " {
Keywords { "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
}
Program "fp" {
SubProgram "d3d11 " {
Keywords { "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
}
}
 Pass {
  Name "PREPASS"
  Tags { "IGNOREPROJECTOR" = "true" "LIGHTMODE" = "PREPASSFINAL" "QUEUE" = "Transparent" "RenderType" = "Transparent" }
  Blend SrcAlpha OneMinusSrcAlpha, SrcAlpha OneMinusSrcAlpha
  ZWrite Off
  Cull Off
  GpuProgramID 205019
Program "vp" {
SubProgram "d3d11 " {
Keywords { "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "LIGHTPROBE_SH" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "UNITY_HDR_ON" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "LIGHTPROBE_SH" "UNITY_HDR_ON" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
}
Program "fp" {
SubProgram "d3d11 " {
Keywords { "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "LIGHTPROBE_SH" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "UNITY_HDR_ON" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "LIGHTPROBE_SH" "UNITY_HDR_ON" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
}
}
 Pass {
  Name "DEFERRED"
  Tags { "IGNOREPROJECTOR" = "true" "LIGHTMODE" = "DEFERRED" "QUEUE" = "Transparent" "RenderType" = "Transparent" }
  Blend SrcAlpha OneMinusSrcAlpha, SrcAlpha OneMinusSrcAlpha
  Cull Off
  GpuProgramID 276640
Program "vp" {
SubProgram "d3d11 " {
Keywords { "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "LIGHTPROBE_SH" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "UNITY_HDR_ON" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "LIGHTPROBE_SH" "UNITY_HDR_ON" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
}
Program "fp" {
SubProgram "d3d11 " {
Keywords { "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "LIGHTPROBE_SH" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "UNITY_HDR_ON" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
SubProgram "d3d11 " {
Keywords { "LIGHTPROBE_SH" "UNITY_HDR_ON" "_NORMALS_PERPIXEL" }
"// shader disassembly not supported on DXBC"
}
}
}
}
Fallback "Diffuse"
CustomEditor "Water2DShaderInspector_TM"
}