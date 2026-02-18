#pragma once

#include "module.h"

#include <string>
#include <vector>
#include <mutex>
#include <atomic>
#include <functional>
#include <unordered_map>

// ============================================================
// HTTP 异步请求结果结构体
// 存储一次 HTTP 请求完成后的所有响应信息
// ============================================================
struct HttpResponse
{
    int status = 0;              // HTTP 状态码 (200, 404, 500 等)
    std::string body;            // 响应正文
    std::string error;           // 错误信息（请求失败时填充）
    bool completed = false;      // 请求是否已完成
    bool success = false;        // 请求是否成功（status 2xx）
};

// ============================================================
// SSE（Server-Sent Events）流式数据块
// LLM 流式输出时，每收到一个 data: 行就生成一个 chunk
// ============================================================
struct HttpStreamChunk
{
    std::string data;            // 单次 SSE data 字段内容
    bool is_done = false;        // 是否为 [DONE] 标记（流式结束）
};

// ============================================================
// HTTP 请求头键值对
// ============================================================
struct HttpHeader
{
    std::string key;
    std::string value;
};

// 初始化 HTTP 模块并注册 LuaBridge 绑定
void init_http_module(lua_State* L);

