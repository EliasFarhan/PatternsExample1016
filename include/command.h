#ifndef COMMAND_H
#define COMMAND_H

#include <engine.h>
#include <stack>
#include <memory>

class Command
{
public:
  virtual ~Command() {}
  virtual void execute() = 0;
  virtual void cancel() = 0;
};

class TransformCommand : public Command
{
public:
	TransformCommand(Transform* transform);
protected:
	Transform* transform;
};

class TranslationCommand : public TransformCommand
{
public:
	TranslationCommand(Transform* transform, Vector translate);
	virtual void execute() override;
	virtual void cancel() override;
protected:
	Vector translate;
};

class RotationCommand : public TransformCommand
{
public:
	RotationCommand(Transform* transform, float rotation);
	virtual void execute() override;
	virtual void cancel() override;
protected:
	float rotation;
};

class CommandManager
{
public:
	void DoCommand(Command* command);

	void CancelCommand();
	~CommandManager();

private:
	std::stack<Command*> commands;
};

#endif
