#include <iostream>
#include "TipoSexo.h"
#include "Cliente.h"

int main()
{
	tipoSexo::TipoSexo sx{ tipoSexo::TipoSexo::femenino };

	std::cout << " sexo " << tipoSexo::tipo_sexo_persona(sx);

	std::cout << "Tamano del enum std::uint8_t " << sizeof(tipoSexo::TipoSexo);

	cliente::Cliente c1;

	std::cout << "\nTamano objeto cliente " << sizeof(c1) << " byte";
	std::cout << "\nTamano objeto cliente, id byte" << sizeof(c1, c1.m_id_cliente) << " byte";
	std::cout << "\nTamano objeto cliente, nombre puntero " << sizeof(c1, c1.m_nombres) << " byte";
	std::cout << "\nTamano objeto cliente, telefono size_T " << sizeof(c1, c1.m_num_telefono) << " byte";
	std::cout << "\nTamano objeto cliente, sexo enum uint8_t" << sizeof(c1, c1.m_sexo) << " byte";
	std::cout << "\nTamano objeto cliente, cedua size_t" << sizeof(c1, c1.m_tamano_cedula) << " byte";

	char* num{ new char[]{"hola"}};

	short numo{};

	for (auto it = num; *it != '\0'; ++it)
	{
		std::cout << "iterado char[" << numo << "] : " << *it << "\n";
		++numo;
	}

	for (auto it = num; *it != '\0'; ++it)
	{
		std::cout << *it ;

		
	}

	std::cout << "\nimprimiendo ahora por medio de subindice\n";

	for (std::size_t i{0}; num[i] != '\0'; ++i)
	{

		std::cout << num[i];
		

	}

	//std::cout << "Tamano del enum std::uint8_t " << sizeof(tipoSexo::TipoSexo);
	
	return 0;
}