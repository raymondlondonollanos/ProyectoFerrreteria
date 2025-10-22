#include "Cliente.h"
#include <cassert>

namespace cliente
{
	Cliente::Cliente(char* nombres, char* num_cedula, std::size_t num_telefono, std::uint16_t tamano_nombre, std::uint16_t tamano_cedula, tipoSexo::TipoSexo sexo, std::uint16_t id_cliente)
		:m_nombres{nombres},m_num_cedula{num_cedula},m_num_telefono{num_telefono},
		m_tamano_nomb{tamano_nombre},m_tamano_cedula{tamano_cedula},m_sexo{sexo},
		m_id_cliente{id_cliente}
	{
		assert((m_nombres && m_tamano_nomb >0) && (m_num_cedula && m_tamano_cedula > 0));

	}
}

