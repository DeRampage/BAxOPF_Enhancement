params ["_player","_anchorPosition","_throwSpeed"];
        private ["_v","_g","_x","_y","_v2","_v4","_x2","_angle1","_angle2"];
        // https://en.wikipedia.org/wiki/Trajectory_of_a_projectile
        _v = _throwSpeed;
        _g = 5;
        _x = ((getPosASL _player) distance2D _anchorPosition) max 1;
        _y = ((_anchorPosition select 2) - (getPosASL _player select 2));
        _v2 = _v * _v;
        _v4 = _v2 * _v2;
        _x2 = _x * _x;
        _angle1 = atan ((_v2 + sqrt (_v4 - _g * ((_g * _x2) + (2 * _y * _v2)))) / (_g * _x));
        _angle2 = atan ((_v2 - sqrt (_v4 - _g * ((_g * _x2) + (2 * _y * _v2)))) / (_g * _x));
        _angle1 min _angle2;