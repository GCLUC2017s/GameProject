#include "CKey.h"

bool CKey::flg[256];

bool CKey::push(char k) {
	
	if (KEY(k)){
		return true;
	}
	return false;
	
}

bool CKey::once(char k) {
	if (KEY(k)) {
		if (flg[k]) {
			return false;
		}
		else {
			flg[k] = true;
			return true;
		}
	}
	else {
		flg[k] = false;
	}
	return false;
}