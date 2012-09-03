/**************************************************************************

Pinball
Wico's only game : Af-tor

***************************************************************************/

#include "emu.h"
#include "cpu/m6809/m6809.h"

class wico_state : public driver_device
{
public:
	wico_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag),
		  m_maincpu(*this, "maincpu")
	{ }

protected:

	// devices
	required_device<cpu_device> m_maincpu;

	// driver_device overrides
	virtual void machine_reset();
public:
	DECLARE_DRIVER_INIT(wico);
};


static ADDRESS_MAP_START( wico_map, AS_PROGRAM, 8, wico_state )
	AM_RANGE(0x0000, 0x07ff) AM_RAM
	//AM_RANGE(0x1fe0, 0x1fef) AM_READWRITE(io_r,io_w)
	AM_RANGE(0xf000, 0xffff) AM_ROM
ADDRESS_MAP_END

static ADDRESS_MAP_START( wico_sub_map, AS_PROGRAM, 8, wico_state )
	AM_RANGE(0x0000, 0x07ff) AM_RAM // shared ram with other cpu
	//AM_RANGE(0x1fe0, 0x1fef) AM_READWRITE(io_r,io_w)
	AM_RANGE(0x4000, 0x40ff) AM_RAM //nvram
	AM_RANGE(0x8000, 0x9fff) AM_ROM
	AM_RANGE(0xe000, 0xffff) AM_ROM
ADDRESS_MAP_END

static INPUT_PORTS_START( wico )
INPUT_PORTS_END

void wico_state::machine_reset()
{
}

DRIVER_INIT_MEMBER(wico_state,wico)
{
}

static MACHINE_CONFIG_START( wico, wico_state )
	/* basic machine hardware */
	MCFG_CPU_ADD("maincpu", M6809, 10000000 / 8)
	MCFG_CPU_PROGRAM_MAP(wico_map)
	MCFG_CPU_ADD("cpu2", M6809, 10000000 / 8)
	MCFG_CPU_PROGRAM_MAP(wico_sub_map)
MACHINE_CONFIG_END

/*-------------------------------------------------------------------
/ Af-Tor (1984)
/-------------------------------------------------------------------*/
ROM_START(aftor)
	ROM_REGION(0x10000, "maincpu", 0)
	ROM_LOAD("u25.bin", 0xf000, 0x1000, CRC(d66e95ff) SHA1(f7e8c51f1b37e7ef560406f1968c12a2043646c5))

	ROM_REGION(0x10000, "cpu2", 0)
	ROM_LOAD("u52.bin", 0x8000, 0x2000, CRC(8035b446) SHA1(3ec59015e259c315bf09f4e2046f9d98e2d7a732))
	ROM_LOAD("u48.bin", 0xe000, 0x2000, CRC(b4406563) SHA1(6d1a9086eb1f6f947eae3a92ccf7a9b7375d85d3))
ROM_END

/*-------------------------------------------------------------------
/ Big Top  (1977)
/-------------------------------------------------------------------*/

GAME(1984,  aftor,  0,  wico,  wico, wico_state,  wico,  ROT0,  "Wico",    "Af-Tor",     GAME_IS_SKELETON_MECHANICAL)
