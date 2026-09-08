#include "MiqayelGameMode.h"
#include "MiqayelExplorerCharacter.h"

AMiqayelGameMode::AMiqayelGameMode()
{
    DefaultPawnClass = AMiqayelExplorerCharacter::StaticClass();
}
