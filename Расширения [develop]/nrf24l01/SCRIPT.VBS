Dim objFS, objFileTXT, objFileS2E, strPath, fullPatch,  strTemp, intPos, strNew, WshShell, fileName, ext_mBlock, strFind

'���������� ���������� ����� ���������� mBlock - ��� ����� ��� ��������))))
ext_mBlock = ".s2e"

'������ ��������� �������� ������������ � ������ ���������� ��� ����������� ��������� ������� ����� �������
strFind="//_"

Set objArgs = WScript.Arguments
'������ ���� � ������ ������������� �� ������ �����
fullPatch = objArgs(0)

Set objFS = CreateObject("Scripting.FileSystemObject")
'�������� ����� �������, ��� ���������� ������� ���������� ��� ��������������
CreateObject("Wscript.Shell").CurrentDirectory = Mid(Wscript.ScriptFullName, 1, InStrRev(Wscript.ScriptFullName, "\") - 1)

'������� ����������
Set WshShell = WScript.CreateObject("WScript.Shell")
strPath = WshShell.CurrentDirectory

'�������� �������� �����, ������������� �� ������
fileName = Replace(fullPatch,strPath & "\", "")

'��������� ��������� �� ���� ��������� �� ������
if objFS.GetExtensionName(fullPatch)="txt" then
	'���������, ���� ������� ���� ���������� mBlock � ����������� .s2e
	If not objFS.FileExists(Replace(fullPatch,".txt", ext_mBlock)) Then
		'��������� �������� ���� ��� ������, ������� ���� � ����������� .s2e ��� ������.
		Set objFileTXT = objFS.OpenTextFile(fullPatch)
		Set objFileS2E = objFS.CreateTextFile(Replace(fullPatch,".txt", ext_mBlock), True)
		
		'������ �������� ���������, ���� �� ��������� ����� �����
		Do While Not objFileTXT.AtEndOfStream
			'������ �������
			strTemp = objFileTXT.ReadLine
			'������� ������� ��� ���������� � ������� �������
			intPos = InStr(1, strTemp, strFind, vbTextCompare)
			'���� ������� ����, ��....
			if intPos>0 then
				'��������� ����� ������ �� ������ ������, �� ������ ����������� (����� ����, ��������� ������� �������� �� ��������� ����� ������������"
				strNew = left(strTemp, intPos - 1)
				'����� � ����� ���� ���������� ������
				objFileS2E.Writeline strNew
			else
				'����� � ����� ���� ������ ��� ���� (������ ��� ��������� � ��� ���)
				objFileS2E.Writeline strTemp
			end if
		loop
		'��������� ��, ������ �������!
		objFileTXT.Close
		objFileS2E.Close
		WScript.Echo "��� �������� ��������� �������!"
	else
	WScript.Echo "���� ���������� � ����� ������ ��� ���������� � ������� �����������"
	end if
else
WScript.Echo "������������ ���� ������ ���� ��������� .txt"
end if

Set objFS = Nothing
WScript.Quit 0
