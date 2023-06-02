#pragma once
#include "chatglm.h"
#include "moss.h"
#include "basellm.h"
#include "vicuna.h"

enum LLM_TYPE {
	LLM_TYPE_CHATGLM = 0,
	LLM_TYPE_MOSS = 1,
	LLM_TYPE_VICUNA = 2,
};

class factoryllm {
public:
	factoryllm() {};
	~factoryllm() {};
	fastllm::basellm* createllm(LLM_TYPE type) {
		fastllm::basellm* pLLM = NULL;
		switch (type) {
		case LLM_TYPE_CHATGLM:
			pLLM = new fastllm::ChatGLMModel();
			break;
		case LLM_TYPE_MOSS:
			pLLM = new fastllm::MOSSModel();
			break;
		case LLM_TYPE_VICUNA:
            pLLM = new fastllm::VicunaModel;
			break;
		default:
			break;
		}
		return pLLM;
	};
};