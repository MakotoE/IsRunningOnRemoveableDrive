#include <windows.h>
#include <iostream>
#include <filesystem>

std::wstring_view getDriveTypeName(UINT driveType) {
	switch (driveType) {
	case DRIVE_UNKNOWN:
		return L"DRIVE_UNKNOWN";
	case DRIVE_NO_ROOT_DIR:
		return L"DRIVE_NO_ROOT_DIR";
	case DRIVE_REMOVABLE:
		return L"DRIVE_REMOVABLE";
	case DRIVE_FIXED:
		return L"DRIVE_FIXED";
	case DRIVE_REMOTE:
		return L"DRIVE_REMOTE";
	case DRIVE_CDROM:
		return L"DRIVE_CDROM";
	case DRIVE_RAMDISK:
		return L"DRIVE_RAMDISK";
	}

	throw std::exception();
}

int main() {
	std::vector<std::wstring> pathsToTest{ L"", L"A:\\", L"C:\\", L"E:\\"};

	for (auto& path : pathsToTest) {
		std::wcout << L"Path: " << path << std::endl;
		auto driveType = GetDriveType(path.c_str());
		std::wcout << L"Drive type: " << getDriveTypeName(driveType) << std::endl;
	}
}