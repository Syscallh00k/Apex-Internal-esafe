#include "memory.hpp"
#include "offsets.hpp"
#include "math.hpp"


class BaseEntity
{
public:
	Vector3 Get_Position()
	{
		return read<Vector3>(this + offsets::VecAbs);

	}
	class Position {
	public:
		void Set_Position(Vector3 Position) {
			//	 return write<Vector3>(this + offsets::VecAbs, Position);
		}
		
		Vector3 GetBonePos(uintptr_t ent, int id)
		{
			Vector3 pos = read<Vector3>(this + offsets::VecAbs);
			uintptr_t bones = read<uintptr_t>(this + 0x0);
			Vector3 bone = {};
			UINT32 boneloc = (id * 0x30);
			bone_t bo = {};
			bo = read<bone_t>(bones + boneloc);

			bone.x = bo.x + pos.x;
			bone.y = bo.y + pos.y;
			bone.z = bo.z + pos.z;
			return bone;
		}

	};
	class VA {
	public:
		Vector2 Get_VA()
		{
			return read<Vector2>(this + 0x0);
		}
		void Set_VA(Vector2 ViewAngles)
		{
			//write<Vector2>(this + 0x0, ViewAngles);
		}
	};



};