// test_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>

char h264Buff[] = { 0x00, 0x00, 0x00, 0x01, 0x67, 0x74, 0x00, 0x00, 0x00, 0x01, 0x68, 0x55, 0x00, 0x00, 0x01, 0x65, 0x78 };
char sps[100] = {0};
char pps[100] = { 0 };

int _tmain(int argc, _TCHAR* argv[])
{
	if (0x00 == h264Buff[0] && 0x00 == h264Buff[1] && 0x00 == h264Buff[2] && 0x01 == h264Buff[3] && 0x67 == h264Buff[4])
	{
		int index_sps = 0;
		for (; index_sps < strlen(h264Buff) - 4; index_sps++)
		{
			if (0x00 == h264Buff[index_sps] && 0x00 == h264Buff[index_sps + 1] && 0x00 == h264Buff[index_sps + 2] && 0x01 == h264Buff[index_sps + 3] && 0x68 == h264Buff[index_sps + 4])
			{
				strncpy_s(sps, h264Buff + 4, index_sps - 4);
				//sps = Base64.encodeToString(h264Buff, 4, index_sps - 4, Base64.NO_WRAP);

				int index_pps = index_sps + 5;
				for (; index_pps < strlen(h264Buff) - 3; index_pps++)
				{
					if (0x00 == h264Buff[index_pps] && 0x00 == h264Buff[index_pps + 1] && 0x01 == h264Buff[index_pps + 2])
					{
						strncpy_s(pps, h264Buff+ index_sps + 4, index_pps - index_sps - 4);
						//pps = Base64.encodeToString(h264Buff, index_sps + 4, index_pps - index_sps - 4, Base64.NO_WRAP);
					}
				}

			}
		}

	}

	return 0;
}

