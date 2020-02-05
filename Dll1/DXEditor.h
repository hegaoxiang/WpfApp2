#pragma once
#include "DXSample.h"

using Microsoft::WRL::ComPtr;

class DXEditor: public DXSample
{
public:
	DXEditor(UINT width, UINT height, std::wstring name);

	virtual void OnInit() override;


	virtual void OnUpdate() override;


	virtual void OnRender() override;


	virtual void OnDestroy() override;

private:
	void LoadPipeline();
	void LoadAssets();
	void PopulateCommandList();
	void WaitForPreviousFrame();
private:
	static const UINT FrameCount = 2;		// ���������õĻ�����������

	ComPtr<ID3D12Device> m_device;
	ComPtr<ID3D12CommandQueue> m_commandQueue;
	ComPtr<ID3D12GraphicsCommandList> m_commandList;
	ComPtr<ID3D12CommandAllocator> m_commandAllocator;
	ComPtr<IDXGISwapChain3> m_swapChain;
	ComPtr<ID3D12PipelineState> m_pipelineState;
	ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
	//ComPtr<ID3D12DescriptorHeap> m_dsvHeap;

	UINT m_rtvDescriptorSize;
	//UINT m_dsvDescriptorSize;

	ComPtr<ID3D12Resource> m_renderTargets[FrameCount];

	UINT m_currentFrameIndex;		// ��ǰ�������ĵ�ַ��0�ǵ�һ����������1�ǵڶ������ȵ�

	
	 // Synchronization objects.
	HANDLE m_fenceEvent;
	ComPtr<ID3D12Fence> m_fence;
	UINT64 m_fenceValue;
};

