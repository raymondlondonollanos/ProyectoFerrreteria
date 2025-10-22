#pragma once
#ifndef CLIENTE_H
#define CLIENTE_H
#include <cstddef>
#include <cstdint>
#include "TipoSexo.h"
#include <cassert>

namespace cliente
{

	class Cliente
	{
	public:
		
		char* m_nombres{ nullptr };
		char* m_num_cedula{ nullptr };
		std::size_t m_num_telefono{};
		std::uint16_t m_id_cliente{};
		tipoSexo::TipoSexo m_sexo{};
		std::uint16_t m_tamano_nomb{};
		

	public:

		Cliente() = default;
		Cliente(char* nombres, char* num_cedula, std::size_t num_telefono, 
			std::uint16_t id_cliente, tipoSexo::TipoSexo sexo);

		//constructor de copias
		Cliente(const Cliente& copy);

		Cliente& operator=(const Cliente& copy);

		//Las funciones que devuelven o reciben y que son una sola asignacion se pueden manejar en 
		//en el archivo .h sin problemas
		char& operator[](std::uint16_t indice)
		{
			assert(indice >= 0 && indice < m_tamano_nomb);

			return m_nombres[indice];
		}

		const char& operator[](std::uint16_t indice) const
		{
			assert(indice >= 0 && indice < m_tamano_nomb);

			return m_nombres[indice];
		}

		Cliente(Cliente&& move);

		Cliente& operator =(Cliente&& move);

	};

}

#endif // !CLIENTE_H

