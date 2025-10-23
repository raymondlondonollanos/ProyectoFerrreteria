#include "Cliente.h"
#include <cassert>

namespace cliente
{
	Cliente::Cliente(char* nombres, char* num_cedula, std::size_t num_telefono,
		std::uint16_t tamano_nombre, std::uint16_t tamano_cedula, 
		tipoSexo::TipoSexo sexo, std::uint16_t id_cliente)

		:m_nombres{nombres},m_num_cedula{num_cedula},m_num_telefono{num_telefono},
		m_tamano_nomb{tamano_nombre},m_tamano_cedula{tamano_cedula},m_sexo{sexo},
		m_id_cliente{id_cliente}
	{
		assert((m_nombres && m_tamano_nomb >0) && (m_num_cedula && m_tamano_cedula > 0));

	}
	Cliente::Cliente(const Cliente& copy)
	{
		deep_coopy(copy);
	}
	Cliente& Cliente::operator=(const Cliente& copy)
	{
		if (this != &copy)
		{
			deep_coopy(copy);
		}

		return *this;
	}

	Cliente::Cliente(Cliente&& move) noexcept
	{
		//movemos los recurso no los copiamos
		m_nombres = move.m_nombres;
		m_tamano_nomb = move.m_tamano_nomb;

		m_num_cedula = move.m_num_cedula;
		m_tamano_cedula = move.m_tamano_cedula;

		//establecemos a nullptr los punteros para no tener dos apuntadores a la misma memoria 
		move.m_nombres = nullptr;
		move.m_num_cedula = nullptr;

		
		m_num_telefono = move.m_num_telefono;
		m_sexo = move.m_sexo;
		m_id_cliente = move.m_id_cliente;

		move.m_num_telefono = 0 ;
		move.m_sexo = tipoSexo::TipoSexo::indefinido;
		move.m_id_cliente = 0;


	}

	Cliente& Cliente::operator =(Cliente&& move)noexcept
	{
		if (this == &move)
		{
			return *this;
		}
		//Primer verficamos que los punteros no posean datos y reestablecemos su tamano y lo que almaena
		delete[] m_nombres;
		m_nombres = nullptr;
		m_tamano_nomb = 0;

		delete[] m_num_cedula;
		m_num_cedula = nullptr;
		m_tamano_cedula = 0;

		//movemos los recurso no los copiamos
		m_nombres = move.m_nombres;
		m_tamano_nomb = move.m_tamano_nomb;

		m_num_cedula = move.m_num_cedula;
		m_tamano_cedula = move.m_tamano_cedula;

		//establecemos a nullptr los punteros para no tener dos apuntadores a la misma memoria 
		move.m_nombres = nullptr;
		move.m_num_cedula = nullptr;


		m_num_telefono = move.m_num_telefono;
		m_sexo = move.m_sexo;
		m_id_cliente = move.m_id_cliente;

		move.m_num_telefono = 0;
		move.m_sexo = tipoSexo::TipoSexo::indefinido;
		move.m_id_cliente = 0;

		return *this;
	}

	Cliente::~Cliente()
	{
		if (m_nombres) {
			delete[] m_nombres;
			m_nombres = nullptr;
		}
		if (m_num_cedula) {
			delete[] m_num_cedula;
			m_num_cedula = nullptr;
		}
	}

	void Cliente::deep_coopy(const Cliente& copy)
	{
		//reestablecer los valores de los punteros y valores del array a cero para 
		delete[] m_nombres;
		m_nombres = nullptr;
		m_tamano_nomb = 0;

		delete[] m_num_cedula;
		m_num_cedula = nullptr;
		m_tamano_cedula = 0;

		//ahora reestablecemos a cero los valores qeu no son punteros
		m_num_telefono = 0;
		m_sexo = tipoSexo::TipoSexo::indefinido;
		m_id_cliente = 0;

		//Realizamos la validacion qeu no sea null el puntero y que el tamano sea valido
		if (copy.m_nombres && copy.m_tamano_nomb > 0)
		{
			//ahora inicializamos el puntero y asignamos el tamano
			m_tamano_nomb = copy.m_tamano_nomb;
			m_nombres = new char[m_tamano_nomb];

			for (std::size_t i{ 0 }; i < m_tamano_nomb; ++i)
			{
				m_nombres[i] = copy.m_nombres[i];
			}
		}

		//Realizamos la validacion qeu no sea null el puntero y que el tamano sea valido
		if (copy.m_num_cedula && copy.m_tamano_cedula > 0)
		{
			//ahora inicializamos el puntero y asignamos el tamano
			m_tamano_cedula = copy.m_tamano_cedula;
			m_num_cedula = new char[m_tamano_cedula];

			for (std::size_t i{ 0 }; i < m_tamano_cedula; ++i)
			{
				m_num_cedula[i] = copy.m_num_cedula[i];
			}
		}

		//ahora copiamos los otros datos que no son punteros 
		m_num_telefono = copy.m_num_telefono;
		m_sexo = copy.m_sexo;
		m_id_cliente = copy.m_id_cliente;

	}
}

