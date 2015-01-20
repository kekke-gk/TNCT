echo off
for /L %%i in (1,1,46) do (
	set DIR_NUM=%%i

	if %%i LSS 10 (
		set DIR_NUM=0!DIR_NUM!
	)

	a.exe !DIR_NUM!
)
