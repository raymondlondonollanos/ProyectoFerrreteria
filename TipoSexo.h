#pragma once
#ifndef TIPOSEXO_H
#define TIPOSEXO_H
#include <cstdint>
#include <string>



namespace tipoSexo
{
	enum class TipoSexo :std::uint8_t
	{
		indefinido,
		masculino,
		femenino,
		LGTBI
	};

	constexpr std::string_view tipo_sexo_persona(tipoSexo::TipoSexo sx)
	{
		switch (sx)
		{
		case tipoSexo::TipoSexo::indefinido:
			return "INDEFINIDO";
		case tipoSexo::TipoSexo::masculino:
			return "MASCULINO";
		case tipoSexo::TipoSexo::femenino:
			return "FEMENINO";
		case tipoSexo::TipoSexo::LGTBI:
			return "LGTBI";
		default:
			return "NO ESPECIFICADO";
		}

	}
}

#endif // !TIPOSEXO_H

