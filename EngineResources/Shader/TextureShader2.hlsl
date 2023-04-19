// ���̴��� ¥�ԵǸ� ������ ��Ģ�� ���Ѿ� �Ѵ�.

// 0~ 16�� ���� 
// ������ ���ٰ� ���°� �ƴϿ���.
cbuffer TransformData : register(b0)
{
    float4x4 WorldMatrix;
}

// � ������ ������ ����ü�� ������ �մϴ�.
// ��� �������̰� ��� ���̰�
// �̸� �������
struct Input 
{
	// �ø�ƽ      ������� �������� 
    // ���ؽ� ���̴����ٰ� ������ ��� �س��� ��� �װ� ����� �����.
    // �߿��Ѱ� ���ؽ� ���۰� 
	float4 Pos   : POSITION;
    float4 Color : COLOR;
};

struct OutPut
{
    // �����Ͷ������� �� ��������
    // w���� ����  ����Ʈ ���ϰ� �ȼ� �������� �������� ������ ���� �����ž�.
    float4 Pos : SV_Position;
    float4 Color : COLOR;
};


// �������������

OutPut Texture_VS(Input _Value)
{
    OutPut OutPutValue = (OutPut)0;
	
    OutPutValue.Pos = mul(_Value.Pos, WorldMatrix);
    // OutPutValue.Pos = _Value.Pos;
    OutPutValue.Color = _Value.Color;
	
	// �����ܰ迡�� ����� ������.
    // OutPutValue.Pos *= �������������;

    return OutPutValue;
}

//struct OutColor
//{
//    // ��Ƴ��� ��ȭ���� 0��° ��ȭ���� ����ض�.
//    float4 Color : SV_Target0;
//};

float4 Texture_PS(OutPut _Value) : SV_Target0
{
    return float4(1.0f, 0.0f, 0.0f, 1.0f);
}