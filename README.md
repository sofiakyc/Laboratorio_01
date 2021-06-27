# Laboratorio_01

P: Há variações na temporização por software para os casos acima? Quantifique-as.
R:
Em low optimization e frequência de 24MHz: leva 1 s para acender ou apagar o led.

Alteração da o nível de otimização, mas sem alterar o limite do loop máximo da condição do loop :
	- Alta otimização (high): nem se vê o led piscar. O led fica aceso o tempo todo
	- Low: Leva 1 s para acender ou apagar o led.
	- Baixo nível de otimização (none): O tempo aumenta em 0,5s para acender ou apagar o led leva(1,5s)
	
Alterando a frequência de clock para 120M:
	- None: Reduziu o tempo de estado aceso ou apagado para 0,5s mais ou menos
	- Low: Por volta de 0,8s ficando aceso ou apagado
	- High: Nem se vê o led piscar. O led fica aceso o tempo todo.


P: Qual dos trechos de código acima é mais legível e fácil de se compreender?
GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
GPIOPinWrite(0x40025000, 0x00000010, 0x00000010);
R: GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
É mais rápido de distinguir os valores por meio de nomes de variáveis quando os valores são binários.

P: Qual dos trechos de código acima é mais legível e fácil de se compreender?
GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4);
GPIOPinTypeGPIOOutput(0x40025000, 0x00000011);
R: A segunda opção, talvez não seja usado em um código em situações de mercado por ser hard coded. A primeira opção seria uma melhor escolha, apesar do '|' enganar os olhos desatentos.

