#pragma once

class CCrop
{
public:
	CCrop(CString c_name, int c_level, int c_experience, int c_seasons, int c_firstripe, int c_secondripe);
	~CCrop(void);

	CString timecolor(CTime tm);
	CString InfoStr(CTime sowingtime, bool flower = false);

	CString name;
	int level;
	int experience;
	int seasons;
	int firstripe;
	int secondripe;
	CTime sowingtime;
};

