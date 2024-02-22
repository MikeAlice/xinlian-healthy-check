/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/25 16:03:36

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifdef USE_ALISMS

#include "stdafx.h"
#include "sms/aliyun/AliKeyConfig.h"
#include "NacosClient.h"
#include "ServerInfo.h"

/**
 * 在此完成AliKeyConfig类静态成员变量定义
 */
std::string AliKeyConfig::region = "";
std::string AliKeyConfig::ak = "";
std::string AliKeyConfig::sk = "";

/**
 * 在此完成AliKeyConfig初始化函数的定义
 */
void AliKeyConfig::init(const std::string& fileName, const std::string& prefix /*= "aliyun.sms"*/)
{
	// 已经初始化就不在初始化
	if (!ak.empty()) return;

	// 设置区域ID
	region = "cn-hangzhou";
#ifdef LINUX
	// 从Nacos中获取配置数据
	NacosClient nacosClient(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	YAML::Node node = nacosClient.getConfig(fileName);
	YamlHelper yaml;
	ak = yaml.getString(&node, prefix + ".ak");
	sk = yaml.getString(&node, prefix + ".sk");
#endif
}

#endif // USE_ALISMS