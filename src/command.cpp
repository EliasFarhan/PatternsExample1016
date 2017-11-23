#include <command.h>
#include <iostream>

TransformCommand::TransformCommand(Transform* transform)
{
	this->transform = transform;
}

TranslationCommand::TranslationCommand(Transform* transform, Vector translate):
		TransformCommand(transform)
{
	this->translate = translate;
}

void TranslationCommand::execute()
{
	transform->position.x += translate.x;
	transform->position.y += translate.y;
}

void TranslationCommand::cancel()
{
	transform->position.x -= translate.x;
	transform->position.y -= translate.y;
}
RotationCommand::RotationCommand(Transform* transform, float rotation): TransformCommand(transform)
{
	this->rotation = rotation;
}

void RotationCommand::execute()
{
	transform->angle += rotation;
}
void RotationCommand::cancel()
{
	transform->angle -= rotation;
}

void CommandManager::DoCommand(Command* command)
{
	command->execute();
	commands.push(command);
}

void CommandManager::CancelCommand()
{
	commands.top()->cancel();
	delete commands.top();
	commands.pop();
}

CommandManager::~CommandManager()
{
	while (commands.size() > 0)
	{
		delete commands.top();
		commands.pop();
	}

}
