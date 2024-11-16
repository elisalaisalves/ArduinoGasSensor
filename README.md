# Sistema de Detecção de Gases Industriais com Arduino e IoT :factory::dash:

## Descrição
Este projeto visa desenvolver um sistema de baixo custo para a detecção de gases tóxicos e inflamáveis em ambientes industriais, utilizando a plataforma Arduino e sensores como o MQ-2 e MQ-135. O sistema transmite dados via internet utilizando o protocolo MQTT, permitindo o monitoramento remoto das condições ambientais em tempo real.

## Funcionamento e Uso
<ol>
    <li>Configuração do Sistema:</li>
        <ul>
            <li>Conecte os sensores de gás (MQ-2 e MQ-135) ao Arduino UNO R4 WiFi utilizando os pinos de entrada/saída.</li>
            <li>O Arduino será programado para ler as variações de tensão dos sensores, convertendo esses valores em concentrações de gases.</li>
            <li>O sistema utiliza o protocolo MQTT para enviar os dados para a nuvem, possibilitando o monitoramento remoto via internet.</li>
        </ul>
    <li>Uso:</li>
        <ul>
            <li>Ao detectar uma alta concentração de gases tóxicos ou inflamáveis, o sistema acende uma matriz de LEDs para alertar visualmente sobre o risco.</li>
            <li>O status do sistema pode ser acessado via dashboard disponível na plataforma Arduino Cloud.</li>
        </ul>
</ol>

![Funcionamento](images/funcionamento.png)


## Software Desenvolvido
O código do sistema foi desenvolvido em C/C++ utilizando a plataforma Arduino Cloud. A principal funcionalidade é a leitura dos sensores MQ-2 e MQ-135 e o envio dos dados via protocolo MQTT para uma plataforma de monitoramento em nuvem.

O código e a documentação estão disponíveis no repositório deste projeto.

## Hardware
<ul>
    <li>Plataforma de Desenvolvimento: Arduino UNO R4 WiFi</li>
        <ul>
            <li>14 pinos digitais de entrada/saída, 6 entradas analógicas, conectividade WiFi.</li>
            <li>Matriz de LEDs 12x8 para exibição do status de gases detectados.</li>
        </ul>
    <li>Sensores:</li>
        <ul>
            <li>MQ-135: Sensor de gás para detectar gases tóxicos como amônia, benzeno, dióxido de carbono, entre outros.</li>
            <li>MQ-2: Sensor de gás para detectar gases inflamáveis como GLP, metano, propano, etc.</li>
        </ul>
    <li>Outros componentes</li>
        <ul>
            <li>Mini Protoboard para prototipagem.</li>
            <li>Jumpers e conectores para fazer as conexões necessárias entre o Arduino e os sensores.</li>
        </ul>
</ul>

## Comunicação, Protocolos e Módulos

## Protocolo MQTT
A integração entre o Arduino e o broker MQTT é realizada automaticamente através da plataforma Arduino Cloud, sem necessidade de configuração manual do broker. A comunicação é feita de maneira simplificada, usando a classe ArduinoCloud que gerencia a conexão com a nuvem e o envio de dados. No código, a inicialização do Arduino Cloud ocorre dentro da função setup(), por meio da chamada ArduinoCloud.begi(ArduinoIoTPreferredConnection), que configura a conexão com o broker MQTT da plataforma Arduino Cloud.

## Requisitos para a execução
<ul>
    <li>Hardware: Arduino UNO R4 WiFi, sensores MQ-2, MQ-135, protoboard.</li>
    <li>Software: Arduino Cloud.</li>
</ul>

## Como Reproduzir
### Passo 1: Configuração do Projeto no Arduino IoT Cloud

1. Acesse o Arduino IoT Cloud:
   - Vá para [Arduino IoT Cloud](https://app.arduino.cc/) e faça login com sua conta Arduino. Caso ainda não tenha uma conta, crie uma.

2. Crie um Novo "Thing":
   - Na tela principal do Arduino IoT Cloud, clique em **Create New Thing**.
   - Dê um nome ao seu "Thing" (ex: "Monitoramento de Gás").
   - Selecione a placa do projeto **Arduino Uno R4**.

3. Adicione as Variáveis de Nuvem:
   - Clique em **Add Variable**.
   - Crie as variáveis `gasConcentrationMQ2` e `gasConcentrationMQ135`, ambas do tipo `int`. Marque essas variáveis como **READWRITE** (Ler e Escrever).

4. Configure a Network:
   - Adicione o nome e senha de sua rede.
   - Clique em salvar.

5. Abra o menu Sketch:
   - Adicione dois arquivos e copie os códigos que estão na pasta src.

6.  Instale as Bibliotecas Necessárias:
   - Ainda na aba de Sketch vá para o menu lateral esquerdo na opção de **Libraries**
   - Instale seguintes bibliotecas: `Arduino IoT Cloud` e `Arduino_LED_Matrix`.

7.  Compile e carregue o código
   - No Arduino IDE, clique em Verificar (ícone de check) para compilar o código.
   - Se a compilação for bem-sucedida, clique em Carregar (ícone de seta para a direita) para carregar o código na sua placa Arduino.

## Conclusão


