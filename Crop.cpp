#include "StdAfx.h"
#include "Crop.h"

CCrop::CCrop(CString c_name, int c_level, int c_experience, int c_seasons, int c_firstripe, int c_secondripe)
{
	name = c_name;
	level = c_level;
	experience = c_experience;
	seasons = c_seasons;
	firstripe = c_firstripe;
	secondripe = c_secondripe;
}

CCrop::~CCrop(void)
{
}

CString CCrop::timecolor(CTime tm)
{
	if ((tm.GetHour() >= 0) && (tm.GetHour() <= 8))
		return (_T("Red"));

	return (_T("DarkGreen"));
}

CString CCrop::InfoStr(CTime sowingtime, bool flower)
{
	CString infostr = _T("");
	CString item;
	CTime calctm = sowingtime;

	infostr += _T("<br><b><font color=\"Purple\" size=\"+8\">");
	item.Format(_T("%s"), name);
	infostr += item;
	infostr += _T("<br><br></font></b>");
	infostr += _T("<b>");
	if (flower) 
	{
		item.Format(_T("魅力等级：%u<br>"), level);
		infostr += item;
	}
	else
	{
		item.Format(_T("种植等级：%u<br>"), level);
		infostr += item;
	}
	if (seasons > 1)
	{
		item.Format(_T("收获经验：%u （全季共 %u）<br>"), experience, experience * seasons);
	}
	else
	{
		item.Format(_T("收获经验：%u <br>"), experience);
	}
	infostr += item;
	item.Format(_T("类型：%u 季作物<br>"), seasons);
	infostr += item;
	item.Format(_T("成熟时间：%u 小时 <br>"), firstripe);
	infostr += item;
	if (seasons > 1)
	{
		item.Format(_T("再成熟时间：%u 小时（全季共 %u 小时）<br>"), secondripe, firstripe + secondripe * (seasons - 1));
		infostr += item;
	}
	infostr += _T("<br>");
	infostr += _T("播种时间：<br>");
	item = calctm.Format(_T("%A, %B %d, %Y %I:%M:%S %p"));
	infostr += item;
	infostr += _T("<br><br>");
	if (seasons > 1)
	{
		infostr += _T("第1季收获时间：<br>");
	}
	else
	{
		infostr += _T("收获时间：<br>");
	}
	calctm += firstripe * 3600;
	infostr += _T("<font color=\"");
	infostr += timecolor(calctm);	
	infostr += _T("\">");
	item = calctm.Format(_T("%A, %B %d, %Y %I:%M:%S %p"));
	infostr += item;
	infostr += _T("</font><br>");
	for (int i = 1; i < seasons; i++)
	{
		item.Format(_T("第%u季收获时间：<br>"), i+1);
		infostr += item;
		calctm += secondripe * 3600 * i;
		infostr += _T("<font color=\"");
		infostr += timecolor(calctm);	
		infostr += _T("\">");
		item = calctm.Format(_T("%A, %B %d, %Y %I:%M:%S %p"));
		infostr += item;
		infostr += _T("</font><br>");
	}
	infostr += _T("</b>");

	return infostr;
}

