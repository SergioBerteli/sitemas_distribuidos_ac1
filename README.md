# sitemas_distribuidos_ac1
Utilizar um framework distribuído (MPI ou PVM) para demonstrar como a tarefa de buscar números primos pode ser realizada por computadores em cluster, ou em grid. 

Requisitos para executar o script:
- Acesso ao kernel do Linux (WSL, VM, SO, etc...)
- Docker

Tutorial de como rodar o script:

1. Crie a rede de computadores para containers
```bash
docker network create --driver=bridge --subnet=192.168.0.0/16 br0
```
2. Monte a imagem Docker
```bash
docker build -t nome .
```

3. Abra dois terminais
Cada terminal será responsável por rodar um container (que nesse caso, representará um computador)

4. Execute o container em cada um desses terminais usando a flag -it para abrir um shell, além de incluir a rede criada 
```bash
docker run -it --network=br0 nome-da-imagem
```

5. Com os dois containers rodando, anote os endereços de ip deles. Para mostrar o ip do container, utilize o seguinte comando:
```bash
ip addr show
```

6. Escolhar qualquer container e execute os seguintes comandos para compilar o script:
```bash
make clean
make
```

7. Por ultimo execute o programa utilizando o seguinte comando:

```bash
mpirun --allow-run-as-root main --host ip_container_1:2,ip_container_2:2
```

Onde o ip_container_1 e ip_container_2 são os ips dos containers adquiridos no passo 5.