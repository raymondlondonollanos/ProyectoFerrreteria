#include "Cliente.h"
#include <cassert>
#include <iostream>

namespace cliente
{
	Cliente::Cliente(char* nombres , char* num_cedula, std::size_t num_telefono,
		std::uint16_t tamano_nombre, std::uint16_t tamano_cedula, 
		tipoSexo::TipoSexo sexo, std::uint16_t id_cliente)

		:m_num_telefono{num_telefono},
		m_tamano_nomb{tamano_nombre},m_tamano_cedula{tamano_cedula},m_sexo{sexo},
		m_id_cliente{id_cliente}
	{
		//copia profunda.

		// 3. Reserva NUEVA memoria
		if ((nombres && m_tamano_nomb > 0) && (num_cedula && m_tamano_cedula > 0))
		{
			m_nombres = new char[m_tamano_nomb] {};

			m_num_cedula = new char[m_tamano_cedula] {};

			for (std::uint16_t i{ 0 }; i < m_tamano_nomb; ++i)
			{
				m_nombres[i] = nombres[i];
			}

			for (std::uint16_t i{ 0 }; i < m_tamano_cedula; ++i)
			{
				m_num_cedula[i] = num_cedula[i];
			}
		}
		//assert((nombres && m_tamano_nomb > 0) && (num_cedula && m_tamano_cedula > 0));

	}
	Cliente::Cliente(const Cliente& copy)
	{
		/*Constructor de copia como el objeto donde se realizara la copia se crea e 
		inmediatamente se realiza la copia no es necesario hacer delete  para los 
		punteros y reestablecer los valores a cero, a diferencia del operador de asignacion 
		en el cual el objeto, ya sido creado y no sabemos que hay dentro de este */
		deep_coopy(copy);
	}
	Cliente& Cliente::operator=(const Cliente& copy)
	{
		if (this != &copy)
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
	void Cliente::mostrar_datos() const
	{
		for (std::uint16_t i{ 0 }; i < m_tamano_nomb; ++i)
		{
			std::cout << m_nombres[i];
		}

		for (std::uint16_t i{ 0 }; i < m_tamano_cedula; ++i)
		{
			std::cout <<m_num_cedula[i];
		}
	}
	std::optional<cliente::Cliente> validacionCliente()
	{
	

		char* nombre{ new char[] {"hola"} };

		delete[] nombre;

		nombre = nullptr;

		if (nombre)
		{
			std::size_t m{ 5 };

			std::uint16_t n{ 7 };

			tipoSexo::TipoSexo sexo{ tipoSexo::TipoSexo::femenino };

			return cliente::Cliente{ nombre, nombre, 23432143, n , n, sexo, n };
		}
		else
		{
			return std::nullopt;
		}

		

		
	}
}

