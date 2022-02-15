

#ifndef IGOAP_CLASS_H
#define IGOAP_CLASS_H

// We don't need windows.h in this plugin but many others do and it throws up on itself all the time
// So best to include it and make sure CI warns us when we use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include "shared.hpp"

namespace goap
{

	class IGoap : public RefCounted {
		GDCLASS(IGoap, RefCounted);

	protected:
		static void _bind_methods();

	private:

	public:

		IGoap();
		~IGoap();

	};

}

#endif // ! IGOAP_CLASS_H
