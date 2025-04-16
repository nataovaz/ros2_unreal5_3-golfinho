# Hello World ROS2 Foxy + Unreal Engine 5 + rclUE


**Autor:** Natan Ferreira Rosa de Jesus Vaz — Trabalho de Conclusão de Curso

**Universidade** Universidade Federal de Itajubá

Este projeto é um exemplo mínimo de integração entre Unreal Engine 5.3, ROS2 Foxy e o plugin rclUE, usando um ator C++ (MyActor) como subscriber de mensagens String do ROS2.

## Requisitos
- Unreal Engine 5.3 (compilado para Linux)
- ROS2 Foxy instalado e configurado
- Plugin [rclUE](https://github.com/RobotecAI/rclUE) (copie para a pasta Plugins/ se não estiver instalado globalmente)
- Linux (testado no Ubuntu)

## Estrutura do Projeto
- `Source/` — Código C++ do projeto (inclui o MyActor)
- `Config/` — Configurações do projeto Unreal
- `Content/` — Apenas os assets essenciais para abrir o projeto
- `Plugins/rclUE/` — Plugin de integração ROS2 <-> Unreal
- `Campus_Itabira.uproject` — Arquivo do projeto Unreal

## Exemplo de execução

Veja abaixo um print do projeto funcionando, recebendo mensagens do ROS2 no Unreal Engine:

![Hello World funcionando](Screenshot%20from%202025-04-15%2023-34-36.png)

2. **Configure o ambiente ROS2:**
   ```bash
   source /opt/ros/foxy/setup.bash
   ```

3. **Abra o Unreal pelo terminal:**
   ```bash
   /caminho/para/UnrealEditor Campus_Itabira.uproject
   ```

4. **Compile o projeto (se necessário):**
   - Use o menu do Unreal ou `make` se configurado.

5. **Adicione o ator MyActor à cena.**
   - Ele já está configurado para ser subscriber do tópico `/teste_unreal`.

6. **No terminal, publique uma mensagem ROS2:**
   ```bash
   ros2 topic pub /teste_unreal std_msgs/msg/String "{data: 'Hello Unreal'}"
   ```

7. **Veja o log no Unreal:**
   - O Output Log mostrará a mensagem recebida pelo MyActor.

## Observações
- O projeto está limpo, sem arquivos de build, cache ou assets desnecessários.
- Para adicionar outros exemplos, basta criar novos atores ou componentes seguindo o padrão do MyActor.
- Para dúvidas sobre o rclUE, consulte: https://github.com/RobotecAI/rclUE

---

contato: natanvaz27@unifei.edu.br