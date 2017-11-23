#include <command.h>
#include <observer.h>

#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <iostream>
#include <stack>
#include <memory>







int main()
{
	/*CommandManager command_manager;

	Transform transform{{50,100}, 40.0f};

	transform.print();
	command_manager.DoCommand(new TranslationCommand(&transform, {-30.0f,45.0f}));
	command_manager.DoCommand(new RotationCommand(&transform, 90.0f));

	transform.print();
	command_manager.CancelCommand();

	transform.print();
	command_manager.DoCommand(new TranslationCommand(&transform, {100.0f,150.0f}));
	transform.print();
	*/

	Subject subject;
	PrintObserver p1(1);
	PrintObserver p2(2);
	PrintObserver p3(3);

	subject.add_observer(&p1);
	subject.add_observer(&p2);
	subject.add_observer(&p3);

	subject.notify();

	subject.remove_observer(&p2);

	subject.notify();

	return EXIT_SUCCESS;
}
